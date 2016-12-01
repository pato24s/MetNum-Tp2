from Tkinter import *
import math
import os
from PIL import Image, ImageDraw
import PIL.ImageOps 
import io

def guardar(event):
    ps = lienzo.postscript(colormode='monochrome')
    img = Image.open(io.BytesIO(ps.encode('utf-8')))
    img.save('test.bmp')

    im = Image.open("test.bmp")
    inverted_image = PIL.ImageOps.invert(im)
    inverted_image.save('invertido.bmp')
    #img = Image.open('ivertido.bmp')
    img = inverted_image.resize((28, 28), PIL.Image.NEAREST)
    #img.save('nuevaMedida.bmp')
    #img = Image.open('nuevaMedida.bmp')
    pix = img.load()
    #print(type (pix))
    img2 = []
    my_output = open('../data/numero.dat', 'w')
    buff = ''
    #print(img.zize())
    #print(img.size[0])
    for i in range(img.size[0]):
        img2_fila = []
        for j in range(img.size[1]):
            pixel = pix[j,i]
            print(pixel)
            pixel_cromatico = 0.2989 * pixel[0] + 0.5870 * pixel[1] + 0.1140 * pixel[2] 
            img2.append(int(pixel_cromatico))
            buff += str(int(pixel_cromatico))+' '
    buff = buff +'/'
    
    my_output.write(buff)
    root.quit()

def dibujar(event):
    lienzo.create_oval(event.x, event.y, event.x+1, event.y+1,width = 20)


root = Tk()
lienzo = Canvas(root, width=300, height=300, background= 'white')
lienzo.bind("<B1-Motion>", dibujar)
lienzo.bind("<Button-3>", guardar)
lienzo.pack()

root.mainloop()