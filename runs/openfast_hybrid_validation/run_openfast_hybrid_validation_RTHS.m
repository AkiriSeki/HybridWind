TMax = 60;
FAST_InputFileName = './input_files/Simulink_LC43_Ptfm.fst';
sim('openfast_validation_test_RTHS.slx',[0,TMax]);
% sim('hybrid_model_RTHS.slx',[0,TMax]);