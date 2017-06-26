import os
import re

# 2-9,12-19
# 16-
def range_to_list(rng, max=None):
    res = []
    if (rng != ""):
        for i in rng.split(","):
            if "-" in i:
                start, end = i.split("-")
                if (end is None):
                    end = max
                rngobj = range(int(start), int(end) + 1)
                res.extend(list(rngobj))
            else:
                res.append(int(i))
    return res


def get_pids():
    pids = set()
    for item in os.listdir('/proc'):
        try:
            pids.add(int(item))
        except:
            pass
    return pids

def get_tids():
    pids = get_pids()
    tids = set()
    for pid in pids:
        for item in os.listdir('/proc/' + str(pid) + '/task/'):
            try:
                tids.add((pid, int(item)))
            except:
                pass
    return tids

def get_thread_info((pid, tid)):
    info = {}
    info['proc_name'] =  open('/proc/' + str(pid) + '/comm').read().strip()
    info['thread_name'] = open('/proc/' + str(pid) + '/task/' + str(tid) + '/comm').read().strip()
    info['cpuset'] =  open('/proc/' + str(pid) + '/task/' + str(tid) + '/cpuset').read().strip()
    for line in open('/proc/' + str(pid) + '/task/' + str(tid) + '/status'):
        if 'Cpus_allowed_list:' in line:
            info['allowed_cpus'] = set(range_to_list(line.split(':')[1].strip()))
            info['allowed_cpus_str'] = line.split(':')[1].strip()
            return info


try:
    online_cpus = set(range_to_list(open("/sys/devices/system/cpu/online").read().strip()))
except Exception as e:
    online_cpus = set()

try:
    system_isolated_cpus = set(range_to_list(open("/sys/devices/system/cpu/isolated").read().strip()))
except Exception as e:
    system_isolated_cpus = set()

system_allocated_cpus = online_cpus - system_isolated_cpus

tids = get_tids()
thread_info = {}
for tid in tids:
    thread_info[tid] = get_thread_info(tid)
    #print thread_info[tid]

for cpu in online_cpus:
    thread_info_for_cpu = [v for v in thread_info.values() if cpu in v['allowed_cpus']]
    for i in thread_info_for_cpu:
        print '{cpu:5} {proc_name:30} {thread_name:30} {allowed_cpus_str}'.format(cpu=cpu, **i)

