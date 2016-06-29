which java
cd /Users/Wuyang/Desktop/machineL/java/
 java -classpath libsvm.jar svm_scale -l 0 -u 1 -s C_price_FBScaleP C_price_FB > C_price_FBScale
java -classpath libsvm.jar svm_train -s 3 -t 2 -c 1 -g 1  C_price_FBScale
java -classpath libsvm.jar svm_scale -r C_price_FBScaleP C_predict_FB > C_predict_FBScale
java -classpath libsvm.jar svm_predict C_predict_FBScale C_price_FBScale.model C_predictPrice_FB