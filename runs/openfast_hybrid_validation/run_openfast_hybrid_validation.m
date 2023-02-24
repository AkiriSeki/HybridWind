TMax = 60;
FAST_InputFileName = './input_files/Simulink_LC43_Ptfm.fst';
tic
sim('openfast_validation_test.slx',[0,TMax]);
toc