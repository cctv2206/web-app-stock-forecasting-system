which java
cd /Users/Wuyang/Desktop/machineL/java/
 java -classpath libsvm.jar svm_scale -l 0 -u 1 -s C_price_GOOGScaleP C_price_GOOG > C_price_GOOGScale
java -classpath libsvm.jar svm_train -s 3 -t 2 -c 1 -g 1  C_price_GOOGScale
java -classpath libsvm.jar svm_scale -r C_price_GOOGScaleP C_predict_GOOG > C_predict_GOOGScale
java -classpath libsvm.jar svm_predict C_predict_GOOGScale C_price_GOOGScale.model C_predictPrice_GOOG