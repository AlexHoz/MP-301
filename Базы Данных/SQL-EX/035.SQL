SELECT model, type
FROM Product 
WHERE model NOT LIKE '%[^a-zA-Z]%' OR model NOT LIKE '%[^0-9]%'
