use elibillinger;
DROP TABLE IF EXISTS orders;
DROP TABLE IF EXISTS customer;
DROP TABLE IF EXISTS product;
CREATE TABLE customer (
    id int NOT NULL AUTO_INCREMENT,
    first_name varchar(255),
    last_name varchar(255),
    email varchar(255),
    PRIMARY KEY (id)
);
CREATE TABLE product (
    id int NOT NULL AUTO_INCREMENT,
    product_name varchar(255),
    image_name varchar(255),
    price decimal(6,2),
    in_stock int,
    PRIMARY KEY (id)
);
CREATE TABLE orders (
    id int NOT NULL AUTO_INCREMENT,
    product_id int NOT NULL,
    customer_id int NOT NULL,
    quantity int,
    price decimal(6,2),
    tax decimal(6,2),
    donation decimal(4,2),
    timestamp bigint,
    PRIMARY KEY (id),
    FOREIGN KEY (product_id) REFERENCES product(id),
    FOREIGN KEY (customer_id) REFERENCES customer(id)
);
INSERT INTO customer (first_name, last_name, email)
VALUES ('Mickey','Mouse','mmouse@mines.edu');
INSERT INTO customer (first_name, last_name, email)
VALUES ('Eli','Billinger','elibillinger@mines.edu');
INSERT INTO product (product_name, image_name, price,in_stock)
VALUES ('CPU','cpu.jpg','99.99','0');
INSERT INTO product (product_name, image_name, price,in_stock)
VALUES ('GPU','gpu.jpg','299.99','6');
INSERT INTO product (product_name, image_name, price,in_stock)
VALUES ('motherboard','motherboard.jpg','49.99','37');