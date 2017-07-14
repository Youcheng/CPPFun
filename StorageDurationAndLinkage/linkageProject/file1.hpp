#pragma once

// extern here and x is not initialized
// it means it is only a declaration of x here without definition
extern int x;

// const int z; means it z is default internal linkage
// put an extern there to make ze have external linkage
extern const int z;
