import numpy as np
from dronekit import *


def pure_pursuit(p1, p2, pos, velvec):
    lkd = 1
    m = (p2[1] - p1[1])/(p2[0] - p1[0])
    theta = np.arctan(m) #slope of the path
    projdist = abs(np.multiply(np.subtract(p1,p2),np.subtract(p1,pos)))/np.linalg.norm(np.subtract(p1,pos))
    gpdist = projdist + lkd
    gp = list(p1[0] + gpdist*np.cos(theta),p1[1] + gpdist*np.sin(theta))#gives goal point coordinates
    chord = np.linalg.norm(np.subtract(pos,gp))
    turntheta = np.arccos(np.multiply(velvec,gp-pos)/(np.linalg.norm(velvec)*np.linalg.norm(gp-pos)))
    radiusofarc = chord/(2*np.sin(turntheta))
    return radiusofarc


def turn_vehicle():
    