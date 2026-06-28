import cv2

# 加载预训练模型
model = cv2.face.LBPHFaceRecognizer_create()
model.read('trained_model.yml')

# 加载人脸检测分类器
face_detector = cv2.CascadeClassifier(cv2.data.haarcascades + "haarcascade_frontalface_default.xml")

cap = cv2.VideoCapture(0)
font = cv2.FONT_HERSHEY_SIMPLEX

while True:
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face_detector.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(100, 100))

    for (x, y, w, h) in faces:
        face = gray[y:y+h, x:x+w]
        label, confidence = model.predict(face)

        # 显示结果
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)
        cv2.putText(frame, f"ID: {label} ({confidence:.2f})", (x, y - 10), font, 0.7, (0, 255, 0), 2)

    cv2.imshow('Face Recognition', frame)

    if cv2.waitKey(1) == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()