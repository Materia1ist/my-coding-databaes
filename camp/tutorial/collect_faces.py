import cv2
import os

# 创建存储人脸数据的文件夹
dataset_dir = 'dataset'
if not os.path.exists(dataset_dir):
    os.makedirs(dataset_dir)

# 用户 ID 输入
user_id = input("请输入用户ID（数字）: ")
cam = cv2.VideoCapture(0)
face_detector = cv2.CascadeClassifier("haarcascade_frontalface_default.xml")

count = 0
while True:
    ret, img = cam.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = face_detector.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(100, 100))

    for (x, y, w, h) in faces:
        count += 1
        face_img = gray[y:y+h, x:x+w]
        cv2.imwrite(f"{dataset_dir}/{user_id}_{count}.jpg", face_img)
        cv2.rectangle(img, (x, y), (x+w, y+h), (255, 0, 0), 2)
        cv2.imshow('Collecting Faces', img)

    if cv2.waitKey(1) & 0xFF == ord('q') or count >= 30:
        break

cam.release()
cv2.destroyAllWindows()
print("人脸图像已保存")
