--Задание 16
SELECT DISTINCT A.model AS model_1, B.model AS model_2, A.speed, A.ram 
FROM pc AS A, pc B
WHERE A.speed = B.speed AND A.ram = B.ram AND A.model > B.model

--Дополнительные задания из лабораторной
--1.2
SELECT DISTINCT A.model AS model_1, B.model AS model_2, A.price
FROM printer AS A, printer B
WHERE A.price = B.price AND A.model < B.model
