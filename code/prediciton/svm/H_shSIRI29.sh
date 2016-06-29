which java
cd /Users/Wuyang/Desktop/machineL/java/
 java -classpath libsvm.jar svm_scale -l 0 -u 1 -s H_price_SIRI29ScaleP H_price_SIRI29 > H_price_SIRI29Scale
java -classpath libsvm.jar svm_train -s 3 -t 2 -c 1 -g 1  H_price_SIRI29Scale
java -classpath libsvm.jar svm_scale -r H_price_SIRI29ScaleP H_predict_SIRI29 > H_predict_SIRI29Scale
java -classpath libsvm.jar svm_predict H_predict_SIRI29Scale H_price_SIRI29Scale.model H_predictPrice_SIRI29