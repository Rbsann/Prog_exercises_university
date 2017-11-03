import numpy as np
import csv
from operator import itemgetter
import io
import sys
inFile=sys.argv[1]
results=[]
with open (inFile, 'r') as inputfile:
    for line in inputfile:
        results.append(list(map(float,line.split())))
f=open("Esqueleto.kml","a+")
f.write('\n')
for i in range(len(results)):
    temp=int(results[i][3])
    f.write('\t \t <Placemark>\n')
    f.write('\t \t \t <name></name>\n')
    f.write('\t \t \t <description>magnitude='+str(results[i][3])+'</description\n')
    f.write('\t \t \t <LookAt>\n')
    f.write('\t \t \t \t <longitude>'+str(results[i][1])+'</longitude>\n')
    f.write('\t \t \t \t <latitude>'+str(results[i][0])+'</latitude>\n')
    f.write('\t \t \t \t <altitude>'+str(results[i][2])+'</altitude>\n')
    f.write('\t \t \t \t <heading>0.0003004541752917533</heading>\n')
    f.write('\t \t \t \t <tilt>10.78140673894728</tilt>\n')
    f.write('\t \t \t \t <range>1058.692599503215</range>\n')
    f.write('\t \t \t \t <gx:altitudeMode>relativeToSeaFloor</gx:altitudeMode>\n')
    f.write('\t \t \t </LookAt>\n')
    if(temp==1):
        f.write('\t \t \t <styleUrl>#m_ylw-pushpin</styleUrl>\n')
        f.write('\t \t \t <Point>\n')
        f.write('\t \t \t \t <gx:drawOrder>1</gx:drawOrder>\n')
        f.write('\t \t \t \t <coordinates>'+str(results[i][1])+','+str(results[i][0])+','+str
                (results[i][2])+'</coordinates>\n')
        f.write('\t \t \t </Point>\n')
    elif(temp==2):
        f.write('\t \t \t <styleUrl>#msn_blue-pushpin</styleUrl>\n')
        f.write('\t \t \t <Point>\n')
        f.write('\t \t \t \t <gx:drawOrder>1</gx:drawOrder>\n')
        f.write('\t \t \t \t <coordinates>'+str(results[i][1])+','+str(results[i][0])+','+str
                (results[i][2])+'</coordinates>\n')
        f.write('\t \t \t </Point>\n')
    elif(temp==3):
        f.write('\t \t \t <styleUrl>#msn_grn-pushpin</styleUrl>\n')
        f.write('\t \t \t <Point>\n')
        f.write('\t \t \t \t <gx:drawOrder>1</gx:drawOrder>\n')
        f.write('\t \t \t \t <coordinates>'+str(results[i][1])+','+str(results[i][0])+','+str
                (results[i][2])+'</coordinates>\n')
        f.write('\t \t \t </Point>\n')
    elif(temp==4):
        f.write('\t \t \t <styleUrl>#msn_ltblu-pushpin</styleUrl>\n')
        f.write('\t \t \t <Point>\n')
        f.write('\t \t \t \t <gx:drawOrder>1</gx:drawOrder>\n')
        f.write('\t \t \t \t <coordinates>'+str(results[i][1])+','+str(results[i][0])+','+str
                (results[i][2])+'</coordinates>\n')
        f.write('\t \t \t </Point>\n')
    elif(temp==5):
        f.write('\t \t \t <styleUrl>#msn_pink-pushpin</styleUrl>\n')
        f.write('\t \t \t <Point>\n')
        f.write('\t \t \t \t <gx:drawOrder>1</gx:drawOrder>\n')
        f.write('\t \t \t \t <coordinates>'+str(results[i][1])+','+str(results[i][0])+','+str
                (results[i][2])+'</coordinates>\n')
        f.write('\t \t \t </Point>\n')
    elif(temp==6):
        f.write('\t \t \t <styleUrl>#msn_purple-pushpin</styleUrl>\n')
        f.write('\t \t \t <Point>\n')
        f.write('\t \t \t \t <gx:drawOrder>1</gx:drawOrder>\n')
        f.write('\t \t \t \t <coordinates>'+str(results[i][1])+','+str(results[i][0])+','+str
                (results[i][2])+'</coordinates>\n')
        f.write('\t \t \t </Point>\n')
    elif(temp==7):
        f.write('\t \t \t <styleUrl>#msn_red-pushpin</styleUrl>\n')
        f.write('\t \t \t <Point>\n')
        f.write('\t \t \t \t <gx:drawOrder>1</gx:drawOrder>\n')
        f.write('\t \t \t \t <coordinates>'+str(results[i][1])+','+str(results[i][0])+','+str
                (results[i][2])+'</coordinates>\n')
        f.write('\t \t \t </Point>\n')
    elif(temp==8):
        f.write('\t \t \t <styleUrl>#msn_wht-pushpin</styleUrl>\n')
        f.write('\t \t \t <Point>\n')
        f.write('\t \t \t \t <gx:drawOrder>1</gx:drawOrder>\n')
        f.write('\t \t \t \t <coordinates>'+str(results[i][1])+','+str(results[i][0])+','+str
                (results[i][2])+'</coordinates>\n')
        f.write('\t \t \t </Point>\n')
    elif(temp==9):
        f.write('\t \t \t <styleUrl>#msn_cabs</styleUrl>\n')
        f.write('\t \t \t <Point>\n')
        f.write('\t \t \t \t <gx:drawOrder>1</gx:drawOrder>\n')
        f.write('\t \t \t \t <coordinates>'+str(results[i][1])+','+str(results[i][0])+','+str
                (results[i][2])+'</coordinates>\n')
        f.write('\t \t \t </Point>\n')
    elif(temp==10):
        f.write('\t \t \t <styleUrl>#msn_info</styleUrl>\n')
        f.write('\t \t \t <Point>\n')
        f.write('\t \t \t \t <gx:drawOrder>1</gx:drawOrder>\n')
        f.write('\t \t \t \t <coordinates>'+str(results[i][1])+','+str(results[i][0])+','+str
                (results[i][2])+'</coordinates>\n')
        f.write('\t \t \t </Point>\n')
    f.write('\t \t </Placemark>\n')
f.write('\t </Folder>\n')
f.write('</Document>\n')
f.write('</kml>\n')
f.close()
    


