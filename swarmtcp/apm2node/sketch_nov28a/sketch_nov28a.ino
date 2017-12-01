#include <ESP8266WiFi.h>

int message[6000] = {69, 73, 178, 128, 128, 23, 213, 90, 0, 64, 180, 88, 10, 0, 240, 1, 255, 69, 13, 30, 128, 136, 77, 75, 4, 128, 196, 0, 254, 140, 94, 56, 128, 128, 197, 101, 170, 0, 54, 255, 90, 86, 0, 0, 255, 0, 252, 30, 210, 63, 129, 11, 30, 119, 191, 0, 142, 0, 253, 77, 79, 28, 0, 145, 13, 10, 13, 10, 73, 110, 105, 116, 32, 65, 114, 100, 117, 67, 111, 112, 116, 101, 114, 32, 86, 51, 46, 50, 46, 49, 32, 40, 51, 54, 98, 52, 48, 53, 102, 98, 41, 13, 10, 13, 10, 70, 114, 101, 101, 32, 82, 65, 77, 58, 32, 49, 57, 57, 57, 13, 10, 70, 87, 32, 86, 101, 114, 58, 32, 49, 50, 48, 13, 10, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 13, 10, 13, 10, 13, 10, 108, 111, 97, 100, 95, 97, 108, 108, 32, 116, 111, 111, 107, 32, 49, 55, 56, 49, 50, 117, 115, 13, 10, 254, 51, 0, 1, 1, 253, 1, 67, 97, 108, 105, 98, 114, 97, 116, 105, 110, 103, 32, 98, 97, 114, 111, 109, 101, 116, 101, 114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 188, 21, 254, 9, 1, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 4, 3, 151, 163, 254, 9, 2, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 4, 3, 169, 32, 254, 51, 3, 1, 1, 253, 1, 98, 97, 114, 111, 109, 101, 116, 101, 114, 32, 99, 97, 108, 105, 98, 114, 97, 116, 105, 111, 110, 32, 99, 111, 109, 112, 108, 101, 116, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 111, 194, 254, 51, 4, 1, 1, 253, 1, 71, 82, 79, 85, 78, 68, 32, 83, 84, 65, 82, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 116, 206, 73, 110, 105, 116, 32, 71, 121, 114, 111, 42, 254, 9, 5, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 4, 3, 46, 80, 42, 10, 82, 101, 97, 100, 121, 32, 116, 111, 32, 70, 76, 89, 32, 254, 28, 6, 1, 1, 30, 163, 14, 0, 0, 45, 34, 193, 59, 244, 83, 207, 187, 125, 254, 56, 191, 72, 213, 26, 186, 0, 32, 56, 57, 236, 235, 239, 185, 16, 176, 254, 20, 7, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 1, 0, 0, 229, 239, 254, 28, 8, 1, 1, 30, 169, 16, 0, 0, 46, 24, 124, 59, 0, 197, 16, 188, 212, 189, 56, 191, 72, 213, 26, 186, 0, 235, 186, 185, 236, 235, 239, 185, 181, 126, 254, 20, 9, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 1, 0, 0, 39, 213, 254, 9, 10, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 207, 67, 254, 28, 11, 1, 1, 30, 179, 18, 0, 0, 20, 163, 172, 58, 104, 241, 62, 188, 100, 174, 56, 191, 0, 128, 117, 184, 0, 32, 56, 57, 144, 58, 156, 56, 14, 203, 254, 20, 12, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 143, 194, 245, 60, 0, 0, 0, 0, 62, 1, 0, 0, 101, 168, 254, 28, 13, 1, 1, 30, 187, 20, 0, 0, 101, 125, 214, 185, 144, 67, 89, 188, 45, 133, 56, 191, 0, 128, 117, 184, 192, 242, 104, 186, 144, 58, 156, 56, 158, 29, 254, 20, 14, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 143, 194, 245, 189, 0, 0, 0, 0, 62, 1, 0, 0, 66, 46, 254, 51, 15, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 95, 255, 254, 9, 16, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 175, 135, 254, 28, 17, 1, 1, 30, 207, 22, 0, 0, 164, 210, 202, 186, 212, 200, 107, 188, 224, 104, 56, 191, 144, 74, 248, 57, 0, 32, 56, 57, 236, 235, 239, 185, 230, 61, 254, 20, 18, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 236, 81, 184, 189, 0, 0, 0, 0, 62, 1, 0, 0, 93, 197, 254, 28, 19, 1, 1, 30, 214, 24, 0, 0, 80, 231, 252, 186, 67, 39, 117, 188, 154, 92, 56, 191, 0, 128, 117, 184, 0, 32, 56, 57, 144, 58, 156, 56, 81, 22, 254, 20, 20, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 143, 194, 117, 189, 10, 215, 35, 60, 62, 1, 0, 0, 91, 96, 254, 9, 21, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 252, 10, 254, 28, 22, 1, 1, 30, 224, 26, 0, 0, 165, 100, 13, 187, 71, 228, 122, 188, 196, 72, 56, 191, 72, 209, 131, 58, 0, 32, 56, 57, 159, 185, 129, 186, 93, 44, 254, 20, 23, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 163, 188, 10, 215, 35, 60, 62, 1, 0, 0, 157, 219, 254, 28, 24, 1, 1, 30, 232, 28, 0, 0, 49, 88, 26, 187, 171, 178, 126, 188, 71, 67, 56, 191, 144, 74, 248, 57, 0, 235, 186, 185, 236, 235, 239, 185, 197, 191, 254, 20, 25, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 163, 188, 10, 215, 35, 60, 62, 1, 0, 0, 95, 225, 254, 51, 26, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 85, 241, 254, 9, 27, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 242, 235, 254, 28, 28, 1, 1, 30, 242, 30, 0, 0, 29, 17, 38, 187, 23, 50, 129, 188, 173, 65, 56, 191, 72, 209, 131, 58, 64, 133, 57, 58, 144, 58, 156, 56, 158, 9, 254, 20, 29, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 35, 60, 62, 1, 0, 0, 231, 51, 254, 28, 30, 1, 1, 30, 250, 32, 0, 0, 40, 218, 47, 187, 34, 123, 129, 188, 21, 73, 56, 191, 72, 213, 26, 186, 0, 32, 56, 57, 144, 58, 156, 56, 177, 44, 254, 20, 31, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 163, 60, 10, 215, 35, 60, 62, 1, 0, 0, 179, 90, 254, 9, 32, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 199, 244, 254, 28, 33, 1, 1, 30, 3, 35, 0, 0, 127, 100, 32, 187, 224, 116, 129, 188, 211, 64, 56, 191, 144, 74, 248, 57, 0, 32, 56, 57, 236, 235, 239, 185, 95, 43, 254, 20, 34, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 163, 60, 10, 215, 35, 60, 62, 1, 0, 0, 44, 164, 254, 28, 35, 1, 1, 30, 11, 37, 0, 0, 145, 109, 35, 187, 187, 144, 130, 188, 234, 82, 56, 191, 144, 74, 248, 57, 0, 32, 56, 57, 236, 235, 239, 185, 107, 40, 254, 20, 36, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 35, 61, 10, 215, 163, 60, 62, 1, 0, 0, 23, 133, 254, 51, 37, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 75, 227, 254, 9, 38, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 170, 250, 254, 28, 39, 1, 1, 30, 21, 39, 0, 0, 204, 185, 47, 187, 200, 21, 134, 188, 30, 63, 56, 191, 0, 128, 117, 184, 0, 235, 186, 185, 28, 95, 16, 59, 43, 37, 254, 20, 40, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 143, 194, 117, 61, 10, 215, 163, 60, 62, 1, 0, 0, 84, 190, 254, 28, 41, 1, 1, 30, 29, 41, 0, 0, 85, 157, 48, 187, 24, 200, 134, 188, 95, 65, 56, 191, 72, 213, 26, 186, 64, 133, 57, 58, 159, 185, 129, 186, 124, 137, 254, 20, 42, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 205, 204, 76, 61, 10, 215, 35, 60, 62, 1, 0, 0, 97, 47, 254, 9, 43, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 154, 152, 254, 28, 44, 1, 1, 30, 39, 43, 0, 0, 56, 255, 52, 187, 241, 106, 135, 188, 208, 35, 56, 191, 72, 209, 131, 58, 192, 242, 104, 186, 159, 185, 129, 186, 18, 160, 254, 20, 45, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 163, 61, 10, 215, 163, 60, 62, 1, 0, 0, 175, 48, 254, 28, 46, 1, 1, 30, 46, 45, 0, 0, 52, 136, 41, 187, 101, 198, 132, 188, 206, 58, 56, 191, 72, 209, 131, 58, 0, 32, 56, 57, 159, 185, 129, 186, 25, 230, 254, 20, 47, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 163, 61, 10, 215, 35, 60, 62, 1, 0, 0, 68, 190, 254, 51, 48, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 237, 254, 9, 49, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 250, 92, 254, 28, 50, 1, 1, 30, 56, 47, 0, 0, 166, 32, 50, 187, 96, 239, 132, 188, 65, 53, 56, 191, 144, 74, 248, 57, 0, 32, 56, 57, 154, 4, 31, 58, 12, 23, 254, 20, 51, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 143, 194, 117, 61, 10, 215, 35, 60, 62, 1, 0, 0, 172, 80, 254, 28, 52, 1, 1, 30, 64, 49, 0, 0, 209, 229, 65, 187, 248, 246, 132, 188, 158, 30, 56, 191, 72, 213, 26, 186, 0, 56, 186, 186, 159, 185, 129, 186, 214, 67, 254, 20, 53, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 143, 194, 117, 61, 0, 0, 0, 0, 62, 1, 0, 0, 42, 249, 254, 9, 54, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 125, 44, 254, 28, 55, 1, 1, 30, 73, 51, 0, 0, 57, 193, 86, 187, 133, 133, 132, 188, 101, 187, 55, 191, 179, 149, 124, 61, 64, 255, 22, 59, 251, 143, 218, 60, 72, 3, 254, 20, 56, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 41, 92, 143, 61, 0, 0, 0, 0, 62, 1, 0, 0, 233, 204, 254, 28, 57, 1, 1, 30, 82, 53, 0, 0, 120, 206, 74, 187, 220, 128, 131, 188, 115, 180, 55, 191, 72, 213, 26, 186, 192, 242, 104, 186, 236, 235, 239, 185, 118, 32, 254, 20, 58, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 143, 194, 117, 61, 0, 0, 0, 0, 62, 1, 0, 0, 147, 199, 254, 51, 59, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94, 10, 254, 9, 60, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 202, 62, 254, 28, 61, 1, 1, 30, 91, 55, 0, 0, 215, 9, 130, 188, 42, 130, 132, 188, 20, 86, 55, 191, 236, 17, 85, 187, 0, 235, 186, 185, 154, 4, 31, 58, 22, 200, 254, 20, 62, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 205, 204, 76, 61, 0, 0, 0, 0, 62, 1, 0, 0, 161, 201, 254, 28, 63, 1, 1, 30, 99, 57, 0, 0, 210, 53, 248, 187, 213, 218, 133, 188, 58, 84, 55, 191, 72, 213, 26, 186, 192, 242, 104, 186, 144, 58, 156, 56, 190, 71, 254, 20, 64, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 143, 194, 117, 61, 0, 0, 0, 0, 62, 1, 0, 0, 188, 50, 254, 9, 65, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 253, 108, 254, 28, 66, 1, 1, 30, 109, 59, 0, 0, 139, 95, 210, 187, 215, 67, 134, 188, 172, 83, 55, 191, 72, 209, 131, 58, 0, 235, 186, 185, 236, 235, 239, 185, 86, 210, 254, 20, 67, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 41, 92, 143, 61, 0, 0, 0, 0, 62, 1, 0, 0, 189, 61, 254, 28, 68, 1, 1, 30, 117, 61, 0, 0, 217, 198, 72, 187, 199, 247, 133, 188, 156, 60, 55, 191, 144, 74, 248, 57, 0, 235, 186, 185, 154, 4, 31, 58, 142, 101, 254, 20, 69, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 41, 92, 143, 61, 0, 0, 0, 0, 62, 1, 0, 0, 167, 36, 254, 51, 70, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 71, 230, 254, 9, 71, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 144, 98, 254, 28, 72, 1, 1, 30, 137, 63, 0, 0, 252, 36, 70, 187, 110, 65, 133, 188, 159, 37, 55, 191, 144, 74, 248, 57, 0, 32, 56, 57, 154, 4, 31, 58, 49, 136, 254, 20, 73, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 236, 81, 184, 61, 0, 0, 0, 0, 63, 1, 0, 0, 219, 18, 254, 9, 74, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 160, 0, 254, 28, 75, 1, 1, 30, 145, 65, 0, 0, 48, 155, 64, 187, 10, 143, 132, 188, 10, 45, 55, 191, 0, 128, 117, 184, 192, 242, 104, 186, 144, 58, 156, 56, 75, 240, 254, 20, 76, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 163, 61, 0, 0, 0, 0, 63, 1, 0, 0, 160, 144, 254, 28, 77, 1, 1, 30, 154, 67, 0, 0, 63, 31, 48, 187, 162, 181, 131, 188, 97, 36, 55, 191, 0, 128, 117, 184, 0, 235, 186, 185, 144, 58, 156, 56, 211, 245, 254, 20, 78, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 236, 81, 184, 61, 0, 0, 0, 0, 63, 1, 0, 0, 186, 15, 254, 51, 79, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 158, 142, 254, 9, 80, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 192, 196, 254, 28, 81, 1, 1, 30, 162, 69, 0, 0, 153, 61, 2, 188, 233, 252, 132, 188, 101, 51, 55, 191, 154, 134, 42, 59, 0, 32, 56, 57, 241, 64, 149, 58, 106, 216, 254, 20, 82, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 163, 61, 0, 0, 0, 0, 63, 1, 0, 0, 210, 237, 254, 28, 83, 1, 1, 30, 173, 71, 0, 0, 77, 218, 190, 187, 170, 9, 132, 188, 201, 14, 55, 191, 72, 167, 7, 59, 0, 235, 186, 185, 154, 4, 31, 58, 101, 132, 254, 20, 84, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 236, 81, 184, 61, 0, 0, 0, 0, 63, 1, 0, 0, 36, 99, 254, 51, 85, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22, 112, 254, 9, 86, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 173, 202, 254, 28, 87, 1, 1, 30, 182, 73, 0, 0, 70, 72, 62, 187, 27, 69, 132, 188, 114, 2, 55, 191, 144, 74, 248, 57, 0, 32, 56, 57, 154, 4, 31, 58, 185, 126, 254, 20, 88, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 41, 92, 143, 61, 0, 0, 0, 0, 63, 1, 0, 0, 28, 94, 254, 28, 89, 1, 1, 30, 189, 75, 0, 0, 181, 152, 69, 187, 211, 204, 131, 188, 139, 251, 54, 191, 72, 209, 131, 58, 0, 235, 186, 185, 236, 235, 239, 185, 130, 254, 254, 20, 90, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 143, 194, 117, 61, 10, 215, 35, 188, 63, 1, 0, 0, 88, 224, 254, 51, 91, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 119, 199, 254, 9, 92, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 26, 216, 254, 28, 93, 1, 1, 30, 200, 77, 0, 0, 215, 247, 64, 187, 166, 44, 132, 188, 177, 252, 54, 191, 144, 74, 248, 57, 0, 32, 56, 57, 144, 58, 156, 56, 237, 44, 254, 20, 94, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 41, 92, 143, 61, 0, 0, 0, 0, 63, 1, 0, 0, 6, 71, 254, 28, 95, 1, 1, 30, 206, 79, 0, 0, 206, 62, 65, 187, 150, 42, 133, 188, 108, 247, 54, 191, 72, 213, 26, 186, 192, 242, 104, 186, 144, 58, 156, 56, 99, 229, 254, 20, 96, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 163, 61, 0, 0, 0, 0, 63, 1, 0, 0, 244, 45, 254, 9, 97, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 66, 201, 254, 28, 98, 1, 1, 30, 219, 81, 0, 0, 210, 12, 65, 187, 8, 0, 133, 188, 3, 242, 54, 191, 72, 213, 26, 186, 0, 32, 56, 57, 154, 4, 31, 58, 76, 210, 254, 20, 99, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 143, 194, 245, 61, 0, 0, 0, 0, 63, 1, 0, 0, 14, 40, 254, 28, 100, 1, 1, 30, 224, 83, 0, 0, 137, 2, 68, 187, 159, 101, 133, 188, 107, 237, 54, 191, 72, 209, 131, 58, 0, 32, 56, 57, 144, 58, 156, 56, 255, 152, 254, 20, 101, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 184, 30, 5, 62, 0, 0, 0, 0, 63, 1, 0, 0, 125, 157, 254, 51, 102, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 175, 90, 254, 9, 103, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 47, 199, 254, 28, 104, 1, 1, 30, 235, 85, 0, 0, 243, 238, 65, 187, 125, 31, 131, 188, 198, 250, 54, 191, 72, 41, 147, 186, 0, 32, 56, 57, 144, 58, 156, 56, 186, 147, 254, 20, 105, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 184, 30, 5, 62, 0, 0, 0, 0, 63, 1, 0, 0, 73, 175, 254, 28, 106, 1, 1, 30, 241, 87, 0, 0, 44, 96, 68, 187, 254, 198, 130, 188, 55, 33, 55, 191, 72, 209, 131, 58, 0, 32, 56, 57, 154, 4, 31, 58, 182, 88, 254, 20, 107, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 143, 194, 245, 61, 0, 0, 0, 0, 63, 1, 0, 0, 214, 11, 254, 9, 108, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 114, 171, 254, 28, 109, 1, 1, 30, 252, 89, 0, 0, 28, 87, 69, 187, 8, 64, 132, 188, 100, 65, 55, 191, 144, 74, 248, 57, 0, 235, 186, 185, 154, 4, 31, 58, 174, 178, 254, 20, 110, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 41, 92, 15, 62, 0, 0, 0, 0, 62, 1, 0, 0, 224, 98, 254, 28, 111, 1, 1, 30, 5, 92, 0, 0, 198, 172, 71, 187, 7, 81, 133, 188, 165, 73, 55, 191, 0, 128, 117, 184, 0, 32, 56, 57, 144, 58, 156, 56, 173, 144, 254, 20, 112, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 154, 153, 25, 62, 0, 0, 0, 0, 62, 1, 0, 0, 6, 197, 254, 51, 113, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 219, 254, 9, 114, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 171, 156, 254, 28, 115, 1, 1, 30, 13, 94, 0, 0, 251, 123, 65, 187, 48, 31, 133, 188, 148, 96, 55, 191, 0, 128, 117, 184, 0, 32, 56, 57, 144, 58, 156, 56, 202, 123, 254, 20, 116, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 41, 92, 15, 62, 0, 0, 0, 0, 62, 1, 0, 0, 126, 14, 254, 28, 117, 1, 1, 30, 21, 96, 0, 0, 114, 174, 71, 187, 136, 0, 133, 188, 149, 91, 55, 191, 0, 128, 117, 184, 0, 235, 186, 185, 236, 235, 239, 185, 206, 118, 254, 20, 118, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 184, 30, 5, 62, 10, 215, 35, 188, 62, 1, 0, 0, 58, 104, 254, 9, 119, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 248, 17, 254, 28, 120, 1, 1, 30, 30, 98, 0, 0, 231, 80, 65, 187, 214, 234, 132, 188, 121, 100, 55, 191, 72, 213, 26, 186, 0, 235, 186, 185, 236, 235, 239, 185, 138, 252, 254, 20, 121, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 184, 30, 5, 62, 10, 215, 35, 188, 62, 1, 0, 0, 131, 86, 254, 28, 122, 1, 1, 30, 38, 100, 0, 0, 108, 108, 63, 187, 26, 29, 133, 188, 11, 104, 55, 191, 0, 128, 117, 184, 0, 235, 186, 185, 144, 58, 156, 56, 134, 155, 254, 20, 123, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 184, 30, 5, 62, 10, 215, 35, 188, 62, 1, 0, 0, 117, 94, 254, 51, 124, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39, 164, 254, 9, 125, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 79, 3, 254, 28, 126, 1, 1, 30, 50, 102, 0, 0, 203, 88, 64, 187, 178, 154, 134, 188, 227, 112, 55, 191, 0, 128, 117, 184, 192, 242, 104, 186, 144, 58, 156, 56, 243, 203, 254, 20, 127, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 205, 204, 204, 61, 10, 215, 35, 188, 62, 1, 0, 0, 46, 252, 254, 28, 128, 1, 1, 30, 56, 104, 0, 0, 85, 193, 58, 187, 63, 136, 134, 188, 152, 104, 55, 191, 72, 213, 26, 186, 0, 32, 56, 57, 144, 58, 156, 56, 146, 172, 254, 20, 129, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 41, 92, 143, 61, 10, 215, 163, 188, 62, 1, 0, 0, 27, 61, 254, 9, 130, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 114, 42, 254, 28, 131, 1, 1, 30, 66, 106, 0, 0, 73, 124, 62, 187, 207, 13, 134, 188, 243, 112, 55, 191, 0, 128, 117, 184, 192, 242, 104, 186, 241, 64, 149, 58, 146, 2, 254, 20, 132, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 163, 61, 10, 215, 163, 188, 62, 1, 0, 0, 108, 176, 254, 28, 133, 1, 1, 30, 74, 108, 0, 0, 162, 195, 69, 187, 15, 151, 134, 188, 115, 106, 55, 191, 72, 41, 147, 186, 160, 246, 255, 186, 154, 4, 31, 58, 201, 139, 254, 20, 134, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 41, 92, 143, 61, 10, 215, 163, 188, 62, 1, 0, 0, 122, 32, 254, 51, 135, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 231, 51, 254, 9, 136, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 197, 56, 254, 28, 137, 1, 1, 30, 84, 110, 0, 0, 35, 145, 70, 187, 108, 34, 135, 188, 206, 108, 55, 191, 144, 74, 248, 57, 0, 32, 56, 57, 159, 185, 129, 186, 96, 56, 254, 20, 138, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 163, 61, 10, 215, 163, 188, 62, 1, 0, 0, 174, 138, 254, 28, 139, 1, 1, 30, 93, 112, 0, 0, 159, 115, 69, 187, 208, 146, 134, 188, 232, 111, 55, 191, 144, 74, 248, 57, 192, 242, 104, 186, 144, 58, 156, 56, 117, 15, 254, 20, 140, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 163, 61, 10, 215, 163, 188, 62, 1, 0, 0, 180, 147, 254, 9, 141, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 150, 181, 254, 28, 142, 1, 1, 30, 101, 114, 0, 0, 207, 109, 75, 187, 200, 125, 134, 188, 231, 98, 55, 191, 0, 128, 117, 184, 0, 235, 186, 185, 236, 235, 239, 185, 123, 164, 254, 20, 143, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 163, 61, 10, 215, 163, 188, 62, 1, 0, 0, 57, 159, 254, 51, 144, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43, 178, 254, 9, 145, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 155, 127, 254, 28, 146, 1, 1, 30, 109, 116, 0, 0, 133, 132, 67, 187, 105, 143, 136, 188, 195, 104, 55, 191, 0, 128, 117, 184, 0, 235, 186, 185, 144, 58, 156, 56, 63, 25, 254, 20, 147, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 143, 194, 117, 61, 10, 215, 163, 188, 62, 1, 0, 0, 209, 113, 254, 28, 148, 1, 1, 30, 119, 118, 0, 0, 86, 133, 69, 187, 176, 117, 136, 188, 237, 105, 55, 191, 72, 213, 26, 186, 192, 242, 104, 186, 236, 235, 239, 185, 46, 82, 254, 20, 149, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 163, 61, 10, 215, 163, 188, 62, 1, 0, 0, 167, 243, 254, 9, 150, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 28, 15, 254, 28, 151, 1, 1, 30, 126, 120, 0, 0, 36, 178, 72, 187, 171, 175, 136, 188, 169, 119, 55, 191, 72, 209, 131, 58, 0, 235, 186, 185, 159, 185, 129, 186, 0, 64, 254, 20, 152, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 143, 194, 245, 61, 10, 215, 35, 188, 62, 1, 0, 0, 130, 74, 254, 28, 153, 1, 1, 30, 138, 122, 0, 0, 108, 176, 70, 187, 246, 232, 135, 188, 146, 116, 55, 191, 144, 74, 248, 57, 0, 32, 56, 57, 236, 235, 239, 185, 156, 250, 254, 20, 154, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 205, 204, 204, 61, 10, 215, 163, 188, 62, 1, 0, 0, 183, 219, 254, 51, 155, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 85, 254, 9, 156, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 171, 29, 254, 28, 157, 1, 1, 30, 144, 124, 0, 0, 34, 35, 59, 187, 92, 79, 137, 188, 237, 114, 55, 191, 72, 41, 147, 186, 0, 235, 186, 185, 144, 58, 156, 56, 175, 31, 254, 20, 158, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 143, 194, 245, 61, 10, 215, 35, 188, 62, 1, 0, 0, 152, 83, 254, 28, 159, 1, 1, 30, 154, 126, 0, 0, 202, 165, 68, 187, 200, 13, 139, 188, 191, 107, 55, 191, 144, 74, 248, 57, 192, 242, 104, 186, 144, 58, 156, 56, 204, 149, 254, 20, 160, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 143, 194, 245, 61, 10, 215, 35, 188, 62, 1, 0, 0, 138, 161, 254, 9, 161, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 243, 12, 254, 28, 162, 1, 1, 30, 162, 128, 0, 0, 178, 240, 64, 187, 55, 12, 137, 188, 54, 107, 55, 191, 144, 74, 248, 57, 64, 133, 57, 58, 159, 185, 129, 186, 252, 203, 254, 20, 163, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 35, 62, 10, 215, 35, 188, 62, 1, 0, 0, 2, 66, 254, 28, 164, 1, 1, 30, 171, 130, 0, 0, 129, 0, 61, 187, 71, 172, 136, 188, 85, 104, 55, 191, 72, 213, 26, 186, 0, 235, 186, 185, 154, 4, 31, 58, 16, 237, 254, 20, 165, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 154, 153, 25, 62, 10, 215, 35, 188, 62, 1, 0, 0, 108, 25, 254, 51, 166, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 236, 200, 254, 9, 167, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 158, 2, 254, 28, 168, 1, 1, 30, 181, 132, 0, 0, 118, 39, 62, 187, 17, 125, 135, 188, 9, 102, 55, 191, 144, 74, 248, 57, 192, 242, 104, 186, 154, 4, 31, 58, 79, 250, 254, 20, 169, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 10, 215, 35, 62, 10, 215, 35, 188, 62, 1, 0, 0, 44, 105, 254, 28, 170, 1, 1, 30, 189, 134, 0, 0, 172, 205, 56, 187, 109, 104, 131, 188, 138, 123, 55, 191, 0, 128, 117, 184, 0, 235, 186, 185, 144, 58, 156, 56, 106, 30, 254, 20, 171, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 154, 153, 25, 62, 10, 215, 35, 188, 62, 1, 0, 0, 174, 35, 254, 9, 172, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 195, 110, 254, 28, 173, 1, 1, 30, 197, 136, 0, 0, 34, 231, 60, 187, 7, 197, 131, 188, 15, 115, 55, 191, 0, 128, 117, 184, 0, 235, 186, 185, 154, 4, 31, 58, 68, 57, 254, 20, 174, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 154, 153, 25, 62, 10, 215, 35, 188, 62, 1, 0, 0, 57, 54, 254, 28, 175, 1, 1, 30, 207, 138, 0, 0, 110, 13, 64, 187, 113, 255, 130, 188, 205, 134, 55, 191, 0, 128, 117, 184, 0, 32, 56, 57, 236, 235, 239, 185, 84, 68, 254, 20, 176, 1, 1, 74, 0, 0, 0, 0, 0, 0, 0, 0, 154, 153, 25, 62, 10, 215, 35, 188, 62, 1, 0, 0, 75, 75, 254, 51, 177, 1, 1, 253, 3, 80, 114, 101, 65, 114, 109, 58, 32, 82, 67, 32, 110, 111, 116, 32, 99, 97, 108, 105, 98, 114, 97, 116, 101, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 73, 254, 9, 178, 1, 1, 0, 0, 0, 0, 0, 2, 3, 81, 3, 3, 26, 89, 254, 28, 179, 1, 1, 30, 215, 140, 0, 0, 37, 232, 55, 187, 150, 191, 131, 188, 9, 125, 55, 191, 72, 213, 26, 186, 0, 56, 186};
int value = 0;
int sent_counter = 0;



//initial setup for wifi-connection
const char* ssid     = "ROOM 367";
const char* password = "itsnotfree";




const char* ip = "192.168.0.5";//destination-ip
unsigned int port = 9993;//destination-port




void setup() {
  Serial.begin(115200);
  
  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
/******************************wait till connection is estaiblished***************/  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
//*********************************************************//

 

  

  
}

void loop() {
  
  
  //while(!Serial.available())
    //delay(2);

  //data = Serial.read();

  WiFiClient tcpclient;
  
  
  
  while(!tcpclient.connect(ip,port))
 { 
    delay(4);
    
 }  

  
 if(value >= 6000) value = 0; 
 String data = ""; 
  

  for(int i = 0; i < 10; i++)
  {
        data = data + String(char(message[value])); 
        value++;  
  }

  
 tcpclient.print(data);
  
  
  while(tcpclient.available()) char c = tcpclient.read();
  
  tcpclient.stop();
  sent_counter++;
  Serial.println(sent_counter);
  
  delay(4);
   
  
 
  
  
}

