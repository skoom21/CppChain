import subprocess
import json
import pygame
import sys

# Command to execute the C++ program
cpp_command = "./main.cpp"

# Execute the C++ program and capture its output
process = subprocess.Popen(
    cpp_command,
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    shell=True,
    bufsize=1,
    universal_newlines=True,
)

# Initialize Pygame
pygame.init()

# Constants
SCREEN_WIDTH, SCREEN_HEIGHT = 800, 600
BLOCK_WIDTH, BLOCK_HEIGHT = 100, 50
BLOCK_COLOR = (0, 128, 255)
TEXT_COLOR = (255, 255, 255)

# Font
font = pygame.font.Font(None, 36)

# Initialize the Pygame screen
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Blockchain Visualization")

# List to store block data
blocks = []

# Simulation control variables
paused = False
frame_delay = 500  # milliseconds

# Function to parse block data from C++ program's output
def parse_block_data(data):
    try:
        block_data = json.loads(data)
        return block_data
    except json.JSONDecodeError:
        return None

# Main game loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                paused = not paused

    if not paused:
        # Read C++ program's output line by line
        line = process.stdout.readline()
        if line:
            block_data = parse_block_data(line)
            if block_data:
                blocks.append(block_data)

    # Clear the screen
    screen.fill((0, 0, 0))

    # Display blocks
    x, y = 50, 50
    for block in blocks:
        pygame.draw.rect(screen, BLOCK_COLOR, (x, y, BLOCK_WIDTH, BLOCK_HEIGHT))
        text = font.render(f"Block {block['index']}", True, TEXT_COLOR)
        screen.blit(text, (x + 10, y + 10))
        if x < SCREEN_WIDTH - BLOCK_WIDTH - 100:
            x += BLOCK_WIDTH + 50
        else:
            x = 50
            y += BLOCK_HEIGHT + 20

    # Handle mouse hover interactions
    mouse_x, mouse_y = pygame.mouse.get_pos()
    for block in blocks:
        if x <= mouse_x <= x + BLOCK_WIDTH and y <= mouse_y <= y + BLOCK_HEIGHT:
            hover_text = f"Index: {block['index']}\nPrevious Hash: {block['previousHash']}\nMerkle Root: {block['merkleRoot']}\nTimestamp: {block['timestamp']}\nNonce: {block['nonce']}\nHash: {block['hash']}"
            text_surface = font.render(hover_text, True, TEXT_COLOR)
            screen.blit(text_surface, (x, y + BLOCK_HEIGHT + 10))

        if x < SCREEN_WIDTH - BLOCK_WIDTH - 100:
            x += BLOCK_WIDTH + 50
        else:
            x = 50
            y += BLOCK_HEIGHT + 20

    pygame.display.flip()

    pygame.time.delay(frame_delay)

# Clean up
pygame.quit()
process.terminate()
sys.exit()
