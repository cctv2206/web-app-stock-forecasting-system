which java
cd /Users/Wuyang/Desktop/machineL/java/
 java -classpath libsvm.jar svm_scale -l 0 -u 1 -s H_price_SIRI0ScaleP H_price_SIRI0 > H_price_SIRI0Scale
java -classpath libsvm.jar svm_train -s 3 -t 2 -c 1 -g 1  H_price_SIRI0Scale
java -classpath libsvm.jar svm_scale -r H_price_SIRI0ScaleP H_predict_SIRI0 > H_predict_SIRI0Scale
java -classpath libsvm.jar svm_predict H_predict_SIRI0Scale H_price_SIRI0Scale.model H_predictPrice_SIRI0