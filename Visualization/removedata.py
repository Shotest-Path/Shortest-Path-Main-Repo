import subprocess
import os

video_dir = os.path.join(os.getcwd(), "media", "videos")
input_video = os.path.join(video_dir, "DijkstraVisualization.mp4")
output_video = os.path.join(video_dir, "output_qt.mp4")

print(f"Re-encoding video from: {input_video}")

subprocess.run([
    "ffmpeg",
    "-y",
    "-i", input_video,
    "-c:v", "libx264",
    "-profile:v", "baseline",
    "-level", "3.0",
    "-pix_fmt", "yuv420p",
    "-c:a", "aac",
    "-movflags", "+faststart",
    output_video
], check=True)

print(f"Video re-encoded successfully -> {output_video}")

print("Cleaning main_animation.py data section...")

with open(r"main_animation.py", "r") as program:
    code = program.read()

with open(r"data.txt", "r") as f:
    snippet = f.read()

new_code = code.replace(
    f"# Data_S\n{snippet}\n# Data_E",
    "# Data_S\n# Data_E"
)

with open(r"main_animation.py", "w") as program:
    program.write(new_code)