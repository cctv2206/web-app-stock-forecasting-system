which java
cd /Users/Wuyang/Desktop/machineL/java/
 java -classpath libsvm.jar svm_scale -l 0 -u 1 -s C_price_SIRIScaleP C_price_SIRI > C_price_SIRIScale
java -classpath libsvm.jar svm_train -s 3 -t 2 -c 1 -g 1  C_price_SIRIScale
java -classpath libsvm.jar svm_scale -r C_price_SIRIScaleP C_predict_SIRI > C_predict_SIRIScale
java -classpath libsvm.jar svm_predict C_predict_SIRIScale C_price_SIRIScale.model C_predictPrice_SIRI