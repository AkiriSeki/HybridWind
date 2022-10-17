# openfast_hybrid_validation

This is a hybrid model run that uses test data from a fully-numerical OpenFAST run (using the full-scale semisub model) as displacement/velocity inputs. It uses the `validation_test.lsx` Simulink model. Notice the changes in `ElastoDyn.dat`, where we enable the hybrid model code using the `HybridMode` parameter, and disable the turbine DOFs.