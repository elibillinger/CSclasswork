/*
* Project 6
*
* Author: Eli Billinger
*/

Create table business(
ID serial PRIMARY KEY,
name TEXT,
street_address TEXT,
city TEXT,
state TEXT,
zip INTEGER
);

Create table business_type(
business_id serial not null,
type text not null,
Primary Key (business_id, type),
Foreign key (business_id) references business (ID)
);

Create table menu (
url text not null,
label text not null,
business_id integer,
Primary Key (business_id,label),
Foreign key (business_id) references business (ID)
);

Create table chain (
name text primary key,
city text,
state text
);

Alter table business add column chain_name text,
add constraint fk_business_chain foreign key (chain_name) references chain (name);

Create table reviewer (
screen_name text primary key,
identity_provider text,
views int
);

Create table reviewer_business_xref (
views int,
comments text,
rating int,
review_date text,
business_id integer,
reviewer_screen_name text,
reviewer_identity_provider text not null,
Foreign key (business_id) references business (ID),
Foreign key (reviewer_screen_name) references reviewer (screen_name)
);