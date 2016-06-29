which java
cd /Users/Wuyang/Desktop/machineL/java/
 java -classpath libsvm.jar svm_scale -l 0 -u 1 -s C_price_AMZNScaleP C_price_AMZN > C_price_AMZNScale
java -classpath libsvm.jar svm_train -s 3 -t 2 -c 1 -g 1  C_price_AMZNScale
java -classpath libsvm.jar svm_scale -r C_price_AMZNScaleP C_predict_AMZN > C_predict_AMZNScale
java -classpath libsvm.jar svm_predict C_predict_AMZNScale C_price_AMZNScale.model C_predictPrice_AMZN