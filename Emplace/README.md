emplace
-------
Inserts a new element into the container constructed in-place with the given args.

Because the primary advantage of emplacement over insertion is that temporary objects
are neither created nor destroyed, when the value being added is put into the
container via assignment, emplacement’s edge tends to disappear.
