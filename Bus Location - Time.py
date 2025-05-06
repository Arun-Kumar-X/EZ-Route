import tkinter as tk
from tkinter import ttk
from PIL import Image, ImageTk
from geopy.distance import geodesic
from datetime import datetime

# Functions
def time():
    Stop_A = (entry_x.get(), entry_y.get())
    Stop_B = (13.057619712007638, 80.23485224896672)
    Distance = geodesic(Stop_A, Stop_B).kilometers

    current_time = datetime.now()
    real_time = int(current_time.strftime("%H"))
    
    Speed = {7:5,8:10,9:15,10:20,11:25,12:30,13:35,14:40,15:30,16:25,17:20,18:15,19:10,20:15,21:30,22:40,23:50}
    for i in Speed:
        if real_time == i:
            time = (Distance)/Speed[i]
    display_time = int(time * 60)
    print(display_time)
    Hr = int(current_time.strftime("%H"))
    Min = int(current_time.strftime("%M"))
    for i in range(1,display_time+1):
        if Min < 60 :
            Min += 1
        elif Min == 60:
            Hr += 1
            Min = 1
    global fin_time
    if len(str(Min)) == 1:
        fin_time = str(Hr) + '0'+ str(Min)
        print(fin_time)
        label['text'] = str(Hr) + ':' + '0'+ str(Min)
        
    else:
        fin_time = str(Hr) + str(Min)
        print(fin_time)
        label['text'] = str(Hr) + ':' + str(Min)
        
    



# Setup
window = tk.Tk()
window.geometry('1920x1080')
window.title('Bus Location')

# Images
img = Image.open('background.png')
img_tk = ImageTk.PhotoImage(img)

# Widget
Background = ttk.Label(window, image = img_tk)
entry_x = tk.Entry(window, font = 'Century_Gothic 20', width = 13, borderwidth = 0)
entry_y = tk.Entry(window, font = 'Century_Gothic 20', width = 13, borderwidth = 0)
button = tk.Button(window, text = '  TIME ', borderwidth = 0, font = 'Century_Gothic 22', fg = '#c00000', command = time )
label = tk.Label(window, text = '', font = 'Century_Gothic 56', fg = 'white', bg = '#c00000')

# Layout
entry_x.place(x = 1255, y = 284)
entry_y.place(x = 1550, y = 282)

button.place(x = 1220, y = 469)
label.place(x = 1460, y = 450)

Background.pack()

# Run
window.mainloop()

