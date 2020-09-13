# Инструкция к лабораторной работе
Не нужно делать точно такой же отчёт!!! 

1. Создаём сеть как на картинке(расположение может быть разное, главное подключите также). Для этого нам нужны:
    1. 9 PC (End Devices->End Devices)
    2. 1 PT-Hub (Network Divices->Hubs)
    3. 2 PT-Switch (Network Divices->Switches)
    4. 300 метров витой пары
    
    Примечание: у PT-Switch изначально 4 нужных порта Fast-Ethernet, поэтому не забудьте добавить ещё один порт первому PT-Switch.

    ![Сеть](https://github.com/AlexHoz/MP-301/blob/master/Сети%20ЭВМ/Скриншоты/Lab_1/1.png)

2. Всем PC нужно присвоить IP:
    1. Кликаем на первый PC.
    2. Переходим в Config -> Interface -> FastEthernet0
    3. В IPv4 Address вписываем 192.168.0.1
    4. Закрываем
    5. Переходим к пункту 1, но уже для следующего PC, также последнюю цифру адреса меняем на следующую.
    То есть, для PC0 - 192.168.0.1, для PC1 - 192.168.0.2 и т.д.

    ![IP](https://github.com/AlexHoz/MP-301/blob/master/Сети%20ЭВМ/Скриншоты/Lab_1/2.png)

3. Проверяем сеть:
    1. Кликаем на первый PC.
    2. Переходим в Desktop -> Command Prompt
    3. пишем ping 192.168.0.1, ping 192.168.0.2 и так все ip, всего их 9

    ![ping](https://github.com/AlexHoz/MP-301/blob/master/Сети%20ЭВМ/Скриншоты/Lab_1/3.png)

    ![ping](https://github.com/AlexHoz/MP-301/blob/master/Сети%20ЭВМ/Скриншоты/Lab_1/4.png)

4. Создаём ARP-таблицу(Вообще в лабе это 5й пункт, но пока мы тут сожно сразу сделать.)
    1. В этой же консоли пишем arm -a

    ![arm](https://github.com/AlexHoz/MP-301/blob/master/Сети%20ЭВМ/Скриншоты/Lab_1/5.png)

5. Описываем таблицы адресов коммутаторов(ЭТО 4Й ПУНКТ):
    1. Кликаем на первый PT-Switch
    2. Перходим в CLI и жмём Enter, чтобы можно было вводить команды.
    3. Вводим команду show mac-address-table.
    4. То же делаем для второго PT-Switch.

    ![Switch](https://github.com/AlexHoz/MP-301/blob/master/Сети%20ЭВМ/Скриншоты/Lab_1/6.png)
    ![Switch](https://github.com/AlexHoz/MP-301/blob/master/Сети%20ЭВМ/Скриншоты/Lab_1/7.png)

6. Пишем отчёт по моему примеру.
