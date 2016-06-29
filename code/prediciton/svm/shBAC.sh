which java
cd /Users/Wuyang/Desktop/machineL/java/
 java -classpath libsvm.jar svm_scale -l 0 -u 1 -s C_price_BACScaleP C_price_BAC > C_price_BACScale
java -classpath libsvm.jar svm_train -s 3 -t 2 -c 1 -g 1  C_price_BACScale
java -classpath libsvm.jar svm_scale -r C_price_BACScaleP C_predict_BAC > C_predict_BACScale
java -classpath libsvm.jar svm_predict C_predict_BACScale C_price_BACScale.model C_predictPrice_BAC