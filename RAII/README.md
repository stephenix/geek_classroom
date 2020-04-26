
1. destruct.cc
CreateShape(): return subclass object on heap, may be memory leak. 
class ShapeWrapper: add wrapper layer to solve memory leak.
class Shape: destruct function muse be virtual.

