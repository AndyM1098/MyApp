# MyApp - .NET Console Application

A basic .NET console application demonstrating project structure and best practices.

## Project Structure

```
MyApp/
├── src/                          # Source code directory
│   ├── Program.cs               # Application entry point
│   ├── Models/                  # Data models
│   │   └── User.cs             # Example model
│   └── Services/                # Business logic
│       └── GreetingService.cs  # Example service
├── tests/                        # Unit tests
│   └── UserTests.cs            # Example tests
├── obj/                          # Build artifacts (auto-generated)
├── bin/                          # Compiled output (auto-generated)
├── MyApp.csproj                 # Project file
├── appsettings.json             # Configuration (production)
├── appsettings.Development.json # Configuration (development)
└── .gitignore                   # Git ignore rules
```

## Getting Started

```bash
# Restore dependencies
dotnet restore

# Build the project
dotnet build

# Run the application
dotnet run

# Run tests
dotnet test
```

## Key Concepts

- **Program.cs**: Entry point where application starts
- **Models**: Data structures/classes
- **Services**: Business logic separated from UI
- **appsettings.json**: Configuration values
