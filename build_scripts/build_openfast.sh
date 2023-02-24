mkdir build
cd build/
FC=ifort cmake .. -DDOUBLE_PRECISION=OFF -DOPENMP=ON -DBUILD_OPENFAST_SIMULINK_API=ON -DBUILD_SHARED_LIBS=ON
make -j16
make install
