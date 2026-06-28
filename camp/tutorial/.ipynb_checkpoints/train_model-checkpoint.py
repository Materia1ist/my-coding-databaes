import cv2
import numpy as np
from os import listdir
from os.path import isfile, join

data_path = 'dataset/'
training_data, labels = [], []

onlyfiles = [f for f in listdir(data_path) if isfile(join(data_path, f))]

for file in onlyfiles:
    image_path = data_path + file
    
    # 假设文件名格式是 User.{id}.{num}.jpg
    parts = file.split('.')
    if len(parts) < 4:
        print(f"跳过非法文件名: {file}")
        continue

    try:
        label = int(parts[1])  # 第二个部分是用户ID
    except ValueError:
        print(f"无法解析标签: {file}")
        continue

    image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    training_data.append(np.asarray(image, dtype=np.uint8))
    labels.append(label)

labels = np.array(labels, dtype=np.int32)

model = cv2.face.LBPHFaceRecognizer_create()
model.train(training_data, labels)
model.save('trained_model.yml')
print("模型训练完成并保存为 trained_model.yml")
