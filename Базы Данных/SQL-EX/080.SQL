SELECT DISTINCT maker 
FROM Product
 EXCEPT 
SELECT DISTINCT maker
FROM (SELECT maker, model FROM Product WHERE type = 'PC') pr left join PC on pr.model = PC.model
WHERE code IS NULL
