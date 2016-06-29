which java
cd /Users/Wuyang/Desktop/machineL/java/
 java -classpath libsvm.jar svm_scale -l 0 -u 1 -s C_price_GEScaleP C_price_GE > C_price_GEScale
java -classpath libsvm.jar svm_train -s 3 -t 2 -c 1 -g 1  C_price_GEScale
java -classpath libsvm.jar svm_scale -r C_price_GEScaleP C_predict_GE > C_predict_GEScale
java -classpath libsvm.jar svm_predict C_predict_GEScale C_price_GEScale.model C_predictPrice_GE