which java
cd /Users/Wuyang/Desktop/machineL/java/
 java -classpath libsvm.jar svm_scale -l 0 -u 1 -s C_price_SScaleP C_price_S > C_price_SScale
java -classpath libsvm.jar svm_train -s 3 -t 2 -c 1 -g 1  C_price_SScale
java -classpath libsvm.jar svm_scale -r C_price_SScaleP C_predict_S > C_predict_SScale
java -classpath libsvm.jar svm_predict C_predict_SScale C_price_SScale.model C_predictPrice_S