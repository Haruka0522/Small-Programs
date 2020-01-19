from time import sleep
from time import time
from selenium import webdriver
from selenium.webdriver.common.action_chains import ActionChains

# ドライバーを開く
driver = webdriver.Chrome()

# ウィンドウサイズを固定
# +123としているのは
# 「Chromeは自動テストソフトウェアによって制御されています。」
# という部分を考慮している
window = (500, 420+123)
driver.set_window_size(*window)

# OpenGL版の寿司打を開く
target_url = 'http://typingx0.net/sushida/play.html'
driver.get(target_url)

# 寿司打のゲーム画面をずらすために書く
target_xpath = '//*[@id="game"]/div'
webgl_element = driver.find_element_by_xpath(target_xpath)
actions = ActionChains(driver)
actions.move_to_element(webgl_element).perform()

# クリックする前にロード時間待機
sleep(10)

# スタートボタンの座標
center_x = 250
center_y = 256

# スタートボタンをクリックする
actions = ActionChains(driver)
actions.move_to_element_with_offset(webgl_element, center_x, center_y).click().perform()
print("スタートボタンをクリックしました。")
sleep(5)

#高級をクリック
actions = ActionChains(driver)
actions.move_to_element_with_offset(webgl_element,center_x,center_y+50).click().perform()
print("高級を選択しました")
sleep(5)

#開始のスペースを入力
target_xpath = "/html/body"
element = driver.find_element_by_xpath(target_xpath)
element.send_keys(" ")
print("開始!!")

#総当り入力
start_time = time()
time_limit = 120.0
while time()-start_time < time_limit:
    element.send_keys("abcdefghijklmnopqrstuvwxyz-!?,.")
input("終了するには何か入力してね")


# ドライバーを閉じる
driver.close()
driver.quit()
