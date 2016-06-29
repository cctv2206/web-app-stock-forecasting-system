which java
cd /Users/Wuyang/Desktop/machineL/java/
java -classpath libsvm.jar svm_scale -l 0 -u 1 -s price30ScaleP price30 > price30Scale
java -classpath libsvm.jar svm_train -s 3 -t 2 -c 1 -g 1  price30Scale
java -classpath libsvm.jar svm_scale -r price30ScaleP predict30 > predict30Scale
java -classpath libsvm.jar svm_predict predict30Scale price30Scale.model predictPrice
