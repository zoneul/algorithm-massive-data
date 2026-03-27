import gzip

points = []

# Bangkok: 13.5 <= lat <= 13.9 and 100.4 <= lon <= 100.9
# LA: 33.7 <= lat <= 34.3 and -118.7 <= lon <= -117.9
# NYC: 40.5 <= lat <= 40.9 and -74.3 <= lon <= -73.7
with gzip.open("loc-gowalla_totalCheckins.txt.gz", "rt") as f:
    for line in f:
        user, time, lat, lon, loc_id = line.strip().split()
        
        lat = float(lat)
        lon = float(lon)

        # LA filter
        if 33.7 <= lat <= 34.3 and -118.7 <= lon <= -117.9:
            points.append((lat, lon))

print(len(points))

# save
with open("dataset\\la_points.txt", "w") as f:
    for lat, lon in points:
        f.write(f"{lat} {lon}\n")