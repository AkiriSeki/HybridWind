mkdir build
cd build/
FC=gfortran-9 cmake .. -DBUILD_OPENFAST_SIMULINK_API=ON -DBUILD_SHARED_LIBS=ON
make -j2
make install