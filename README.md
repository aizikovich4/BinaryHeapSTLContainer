# BinaryHeapSTLContainer
Реализовать двоичную кучу в виде современного STL-контейнера.


Выполенная реализация не полностью совместима с stl алгоритмами (это касается в частности итераторов)
так же отсутствует метод get_elements - возвращющий максимальный элемент кучи. Но его всегда можно заменить конструкцией 
if(heap.size())
  return heap[1];
поскольку максимальный элемент всегда первый

requirements for windows : 
  visual studio code 2017, cmake 3.10
requirements for windows : 
  5.3.1, cmake 3.10

build on windows: 
  
  run.bat
  
build on linux: 
  
  run.sh   
  
  (if not running:  chmod +x run.sh)
