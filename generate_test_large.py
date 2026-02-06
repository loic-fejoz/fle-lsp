import random
from datetime import datetime, timedelta

def generate_callsign():
    prefixes = ['K', 'W', 'DL', 'G', 'F', 'JA', 'I', 'VE', 'EA', 'OH']
    suffix = "".join(random.choices("ABCDEFGHIJKLMNOPQRSTUVWXYZ", k=random.randint(1, 3)))
    digit = random.randint(0, 9)
    return f"{random.choice(prefixes)}{digit}{suffix}"

def generate_grid():
    # Generate a random 4-character Maidenhead grid square
    lat_char = random.choice("ABCDEFGHIJKLMNOPQR")
    lon_char = random.choice("ABCDEFGHIJKLMNOPQR")
    lat_num = random.randint(0, 9)
    lon_num = random.randint(0, 9)
    return f"{lat_char}{lon_char}{lat_num}{lon_num}"

def generate_name():
    names = ['John', 'Jane', 'Bob', 'Alice', 'Tom', 'Yuki', 'Hans', 'Pierre', 'Maria', 'Elena']
    return random.choice(names)

def generate_fle(lines=5000):
    modes = ['CW', 'SSB', 'FT8']
    bands = ['40m', '20m', '15m', '10m']
    current_date = datetime(2023, 10, 1)
    
    with open("test_large.fle", "w") as f:
        f.write("mycall MY0CALL\n")
        f.write("mygrid: JN38\n\n")
        
        line_count = 0
        while line_count < lines:
            # New Day Header
            f.write(f"date {current_date.strftime('%Y-%m-%d')}\n")
            f.write(f"{random.choice(bands)} {random.choice(modes)}\n")
            
            # Start time for the day
            hour = 8
            minute = 0
            
            # Generate about 50-100 QSOs per date block
            block_size = random.randint(50, 100)
            for _ in range(block_size):
                if line_count >= lines: break
                
                # Randomly jump time
                minute += random.randint(0, 5)
                if minute >= 60:
                    hour += 1
                    minute = minute % 60
                
                time_str = f"{hour:02d}{minute:02d}"
                call = generate_callsign()
                rst_s = random.choice(["59", "599", "57", "55"])
                rst_r = random.choice(["59", "599", "58", "55"])
                
                extra = ""
                if random.random() < 0.3: # 30% chance for a grid
                    extra += f" {generate_grid()}"
                if random.random() < 0.2: # 20% chance for a name
                    extra += f" @{generate_name()}"

                f.write(f"{time_str} {call} {rst_s} {rst_r}{extra}\n")
                line_count += 1
            
            f.write("\n")
            current_date += timedelta(days=1)

generate_fle(5000)
print("File 'test_large.fle' generated with 5000 QSOs.")
