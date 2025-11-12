import hashlib

# text = "Hello World!"
# hash_object = hashlib.sha256(text.encode()) # Encode my text
# hash_digest = hash_object.hexdigest() # Converts hash_object's text to hexadecimal string.
# print(f"SHA256 Hash of {text}: {hash_digest}")

# Does the same thing as we done before, except it does it for a file not a text.
def hash_file(file_path):
    h = hashlib.new("sha256")
    with open(file_path, "rb") as file:
        while True:
            chunk = file.read(1024) # Reads 1024 byte(1KB) per each loop and in this way large files don’t need to load fully into memory.
            if chunk == b"":
                break
            h.update(chunk)
    return h.hexdigest() # Returns the final hexadecimal hash string (64 characters).

def verify_integrity(file1, file2):
    hash1 = hash_file(file1)
    hash2 = hash_file(file2)

    # Get file names from a file path
    a = file1.split("\\")
    f1 = a[-1]
    b = file2.split("\\")
    f2 = b[-1]

    print("\nChecking integrity between", f1, " and ", f2)

    if hash1 == hash2:
        return "file is intact. No modifications have been made." # intact: Dokunulmamış
    return "File has been modified. Possibly unsafe."

if __name__ == "__main__": # Run the following code only if this file is executed directly, not imported.
    print("SHA Hash of file is: ", hash_file(r"cryptography-basics\venv\sample_files\sample.txt"))
    print(verify_integrity(r"cryptography-basics\venv\sample_files\1-2.svg", r"cryptography-basics\venv\sample_files\1.svg"))
    print(verify_integrity(r"cryptography-basics\venv\sample_files\2.svg", r"cryptography-basics\venv\sample_files\1.svg"))