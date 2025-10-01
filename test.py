import subprocess
import pytest
import os

def run_parser(full_name, email):
    """Helper function to run the C++ parser with input."""

    # Combine inputs with newlines, as if the user pressed Enter after each
    input_text = f"{full_name}\n{email}\n"

    result = subprocess.run(
        ["./parser_app"],
        input=input_text,
        capture_output=True,
        text=True,
        check=True
    )

    # Parse the output to find the key-value pairs
    return result.stdout.strip().replace(" ", "").lower()

def test_simple_name_and_email():
    """Tests a standard first and last name."""
    name = "Jane Doe"
    email = "jane.doe@example.com"

    parsed_info = run_parser(name, email)

    assert "FirstName:Jane".lower() in parsed_info
    assert "LastName:Doe".lower() in parsed_info
    assert "Username:jane.doe".lower() in parsed_info and "@" not in parsed_info
