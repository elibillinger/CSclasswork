Drop table if exists netflix;
Drop table if exists youtube;

Create table netflix(
show_ID text,
type text,
title text,
director text,
country text,
date_added text,
release_year int,
rating text,
duration text
);

Create table youtube(
video_id text,
title text,
published_at timestamp,
channel_id text,
channel_title text,
category_id integer,
trending_date text,
tags text,
view_count integer,
likes integer,
dislikes integer
);



\copy netflix From 'netflix_titles.csv' Delimiter ',' Csv header;
\copy youtube from 'US_youtube_trending_data.csv' Delimiter ',' Csv header;


Delete from netflix where country != 'United States';

Update YouTube set trending_date = replace(youtube.trending_date, 'T00:00:00Z', ' ');

Update netflix set date_added = (date_added || ' ');

\copy (select youtube.trending_date,youtube.view_count from youtube) to 'result.csv' delimiter ',' csv header;