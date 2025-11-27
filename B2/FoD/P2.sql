USE northwind;
-- 1
SELECT product_code, product_name FROM products WHERE discontinued = 1;
-- 2
SELECT * FROM products ORDER BY list_price DESC LIMIT 4;
-- 3
SELECT id, product_name, list_price FROM products WHERE list_price BETWEEN 15 AND 25;
-- 4
SELECT id, CONCAT(first_name, " ", last_name) AS full_name FROM employees;
-- 5
SELECT * FROM employees WHERE LOCATE("A", first_name) = 1;
-- 6
SELECT COUNT(DISTINCT city) FROM employees;
-- 7
SELECT DISTINCT ship_name FROM orders;
-- 8
SELECT MIN(list_price), MAX(list_price) FROM products;
-- 9
SELECT COUNT(*) FROM products WHERE discontinued = 0;
-- 10
SELECT AVG(list_price), STDDEV(list_price) FROM products;
-- 11
SELECT product_name, list_price FROM products WHERE list_price > (SELECT AVG(list_price) FROM products);
-- 12
INSERT INTO suppliers(company, last_name, first_name, city, country_region)
VALUES ("Habeco", "Nguyễn", "Hồng Linh", "Hanoi", "Vietnam");
-- 13
INSERT INTO products(product_code, supplier_ids, list_price, discontinued, category)
VALUES ("TBTrucBach", (SELECT id FROM suppliers WHERE company = "Habeco"), 22, 0, "Beverages");
-- 14
UPDATE products
SET standard_cost = 18 WHERE product_code = "TBTrucBach";
-- 15
DELETE FROM suppliers WHERE company = "Habeco";
