which java
cd /Users/Wuyang/Desktop/machineL/java/
 java -classpath libsvm.jar svm_scale -l 0 -u 1 -s C_price_AAPLScaleP C_price_AAPL > C_price_AAPLScale
java -classpath libsvm.jar svm_train -s 3 -t 2 -c 1 -g 1  C_price_AAPLScale
java -classpath libsvm.jar svm_scale -r C_price_AAPLScaleP C_predict_AAPL > C_predict_AAPLScale
java -classpath libsvm.jar svm_predict C_predict_AAPLScale C_price_AAPLScale.model C_predictPrice_AAPL