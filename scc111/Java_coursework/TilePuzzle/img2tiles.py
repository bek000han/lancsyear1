import sys
from PIL import Image

def crop_to_4_3(img):
    # Get the dimensions of the original image
    width, height = img.size

    # Calculate the target height for a 4:3 aspect ratio
    target_height = width * 3 // 4

    # Check if the image is not in a 4:3 aspect ratio
    if height > target_height:
        # Calculate the cropping box
        upper = (height - target_height) // 2
        lower = height - upper

        # Crop the image to a 4:3 aspect ratio, maintaining a square aspect ratio
        img = img.crop((0, upper, width, min(lower, target_height)))

    return img

def resize_image(img, square_size):
    # Resize the image to the specified square size
    return img.resize((square_size, square_size))

def split_image(input_path, output_path):
    # Open and crop the image if necessary
    img = Image.open(input_path)
    img = crop_to_4_3(img)

    # Get the dimensions of the cropped image
    width, height = img.size

    # Define the size of each square
    square_size = 119

    # Loop through each row and column to crop, resize, and save the squares
    for row in range(3):
        for col in range(4):
            index = row * 4 + col
            left = col * (width // 4)
            upper = row * (height // 3)
            right = left + (width // 4)
            lower = upper + (height // 3)

            # Crop the image
            square = img.crop((left, upper, right, lower))

            # Resize the square
            square = resize_image(square, square_size)

            # Save the square
            square.save(f"{output_path}/tile_{index}.jpg")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python img2tiles.py <input_image_path> <output_directory>")
        sys.exit(1)

    input_image_path = sys.argv[1]
    output_directory = sys.argv[2]

    split_image(input_image_path, output_directory)
