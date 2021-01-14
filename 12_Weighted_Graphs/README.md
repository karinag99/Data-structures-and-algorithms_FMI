# Практикум 12

## Задачи върху теглони графи

### Задача 1
Даден е неориентиран свързан граф G с **n** върха и **n-1** ребра. Дължината на всяко от ребрата е цяло неотрицателно число. Означаваме с d(x,y) дължината на най-късият път между два върха x и y в графът G. 

Дефинираме понятието диаметър на графът G по следния начин: диаметърът на G е най-голямото от числата d(m,n), където m и n са два произволни върха от графа G.


Вашата задача е да напишете програма, намираща диаметърът на даден граф G.
#### Вход:
Всички данни се въвеждат от стандартният вход. 

На първия ред е дадено числото **n** – това е броят на върховете в графа. Върховете в графът са номерирани с целите числа от 1 до n. Всеки от следващите n-1 на брой редове описва едно ребро на G: първите две числа задават краищата на реброто, свързващо върховете x и y, третото число е дължината на реброто d(x,y) и това число е цяло неотрицателно число <  1000.
#### Изход:
На стандартния изход трябва да се изведе единствено търсеният диаметър.


### Задача 2
Имаме мрежа от **n** колектори за вода. Колекторите са номерирани от 1 до n. Знаем че, има **m** тръбопровода между тях, посоката на всеки тръбопровод и процентът на загубената вода при преноса през тръбопровода. Освен това знаме, че съществуват **d** на брой опасни колектори, до които не искаме да досига водата, тъй като ще изчезне безследно. 

Да се намери при подадени **s** и **e** максималното количество останала вода като започнем от колектор **s** и завършим в колектор **e**.

#### Вход:
На първият ред на стандартният вход се въвеждат числата **n**, **m** и **k** - брой колектори, брой тръбопроводи и количество начална вода.

На следващите **m** реда се въвеждат 3 числа, **a**, **b**, **l**, съответно деклариращи, че има тръбопровод от **a** до **b** със загуба **l%** от водата. След тези **m** реда следва число **d**, броят опасни колектори, последнвано от **d** на брой числа - самите опасни колектори. Накрая, се въвеждат числа **s** и **e**, съответно начален и краен колектор.

#### Изход:
Максималното количеството достигнала вода от колектор **s** до колектор **e**, при начално количесто **k**