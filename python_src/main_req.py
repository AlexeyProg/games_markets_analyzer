from bs4 import BeautifulSoup
import requests
import json
import string
import sys


data = {}



def convert(str):
    result_name = ""
    for char in str:
        if char == '\'':
            continue
        elif char == ' ':
            result_name += '-'
        else:
            result_name += char
    result_name = result_name.lower()
    return result_name


def json_file(url1,url2):
    main_req(url1,url2)
    with open("data.json", "w") as json_file:
        json.dump(data,json_file)


def steambuy_request(url):
    response = requests.get(url)
    if response.status_code == 200:
        r_text = response.text
        soup = BeautifulSoup(r_text, 'html.parser')
        product_price_element = soup.find('div', class_='product-price__cost')
        if product_price_element:
            price_text = product_price_element.text.strip()

            data["SteamBuy"] = price_text

        else:
            print("Элемент не найден.")

    # return steambuy_result


def zakazaka_request(url):
    response = requests.get(url)
    if response.status_code == 200:
        r_text = response.text
        soup = BeautifulSoup(r_text, 'html.parser')
        product_price_element = soup.find('div', class_='price')
        if product_price_element:
            price_text = product_price_element.text.strip()
            tr = str.maketrans("", "", string.ascii_letters) # чтобы убрать буквы 

            data["zakazaka"] = price_text.translate(tr)
        else:
            print("Элемент не найден.")



def main_req(steambuy,zakazaka):
    steambuy_request(steambuy)
    zakazaka_request(zakazaka)

def main():

    if len(sys.argv) > 1:
        entered_str = sys.argv[1]
        print(f"str is : {entered_str}")

        game_name =  entered_str
        result_name = convert(game_name)
        result_name2 = convert(game_name)
        str_url = f"https://steambuy.com/steam/{result_name}/"
        str_zaka =  f"https://zaka-zaka.com/game/{result_name2}"
        json_file(str_url, str_zaka)


if __name__ == '__main__':
    main()