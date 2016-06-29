which java
cd /Users/Wuyang/Desktop/machineL/java/
 java -classpath libsvm.jar svm_scale -l 0 -u 1 -s C_price_YHOOScaleP C_price_YHOO > C_price_YHOOScale
java -classpath libsvm.jar svm_train -s 3 -t 2 -c 1 -g 1  C_price_YHOOScale
java -classpath libsvm.jar svm_scale -r C_price_YHOOScaleP C_predict_YHOO > C_predict_YHOOScale
java -classpath libsvm.jar svm_predict C_predict_YHOOScale C_price_YHOOScale.model C_predictPrice_YHOO