from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import NoSuchElementException
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.action_chains import ActionChains
from bs4 import BeautifulSoup
from time import sleep
import csv
driver = webdriver.Chrome(executable_path="/Users/maxvyatkin/Desktop/chromedriver_mac64/chromedriver")
center = [55.755864, 37.617698]
comma = ','
zoom = '10z'
target_point = [55.568494, 37.701466]
i = "i"
trb = 'trb'




for p in range(1, 20):
    url = 'https://votetovid.ru/#' + str(center[0]) + comma + str(center[1]) + comma + zoom + comma + str(target_point[0]) + comma + str(target_point[1]) + i + comma + trb
    driver.get(url)
    sleep(1)
    html_ = driver.page_source
    soup = BeautifulSoup(html_, 'lxml')
    span_txHgt = soup.find_all('span')[0]
    height = span_txHgt.text
    print(target_point, height)
    with open('data.csv', 'a') as file:
        writer = csv.writer(file)
        writer.writerow(
            (
                target_point,
                height
            )
        )
    target_point[0] -= 0.000111
    target_point[1] += 0.000111
    p += 1

