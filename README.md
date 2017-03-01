# DEPENDENCIES #
### OpenCV  (> 2.4.x) ###
sudo apt-get install libopencv-dev 

### CGAL (>4.3) ###
download from https://gforge.inria.fr/frs/?group_id=52 the version 4.5, 

extract it into a folder, let's call it "FOLDER" 

open the file CGAL-4.5/include/CGAL/Triangulation_hierarchy_3.h

change line 654 from  
```c++
CGAL_triangulation_precondition(!is_infinite(v)); 
```
to  
```c++ 
CGAL_triangulation_precondition(!this->is_infinite(v)); 
```

open terminal and go into FOLDER/CGAL-4.5 (*cd FOLDER/CGAL-4.5*)

then on terminal:

```
mkdir build

cd build

cmake ..

make

sudo make install
```

### Eigen3 (> 3.0.5) ###
sudo apt-get install libeigen3-dev

### gmp ###
sudo apt-get install libgmp-dev

# Installation #
This library can be installed using the same commands specified for CGAL.
The ``` make install ``` directives will copy all the necessary and a shared library. 
Be aware that together with the headers produced also those belonging to glm are installed, thus if they are already presente please comment the relative install directive in the ``` CMakeLists.txt ``` file.

Notice that to use it the software must be linked with the necessary libraries. An example of a cmake file is provided in the test folder.

# EXAMPLES #
In data folder we put three examples: templeRing and dinoRing comes as part of the Middelbury dataset (http://vision.middlebury.edu/mview/); while 0095 is one of the KITTI sequences (raw data from http://www.cvlibs.net/datasets/kitti/).

We provide only the structure from motion output in a json file, following the specs of OpenMVG. We do not provide the image sequences to avoid copyright infringements. Anyway you can easily download them from the websites.



