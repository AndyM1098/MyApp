# Plan: Port Python Grading Pipeline to C# + ASP.NET Core MVC Dashboard

## Overview
Fully port main_grade.py to C#, housed in MyApp.Core as a service library.
Build the ASP.NET Core MVC dashboard on top of that service. No Python dependency.

## Python to C# Translation Map
- os.fork + os.wait → Task.WhenAll / Parallel.ForEach + SemaphoreSlim throttle
- ZipFile → System.IO.Compression.ZipFile
- tarfile → SharpCompress NuGet package
- shutil.copy/move → File.Copy / File.Move
- subprocess.run (make) → Process.Start + capture stdout/stderr
- argparse → Controller action parameters
- Global config dicts → Static config classes in C#

## Phase 1 - NuGet dependency
Step 1: Add SharpCompress to MyApp.Core (needed for .tar extraction)

## Phase 2 - Core Models (MyApp.Core/src/Models/)
Step 2: GradingConfig.cs - static class holding all lab config dicts (lab_rename_list, correct_lab_name, files_to_copy_over, make_targets, TA section lists)
Step 3: StudentSubmission.cs - Name, TASection, HasCompileError, CompileOutput, GradeOutput, Files
Step 4: LabInfo.cs - LabNumber, StudentCount, GradeProjectRoot

## Phase 3 - GradingService (MyApp.Core/src/Services/GradingService.cs)
Port each Python function 1:1 as an async method:
- UnzipSubmissions(string labNum, bool rerun)
- CreateStudentDirectories(string labNum, bool rerun)
- UntarSubmissions(string labNum, bool rerun)
- CopyFilesToStudents(string labNum, bool rerun)
- CompileCppFiles(string labNum, bool rerun)
- RunGradeScript(string labNum, bool rerun)
- GatherPlagiarismFiles(string labNum)
- GetStudentList(string labNum) returns List<StudentSubmission>
- GetStudentDetail(string labNum, string studentName) returns StudentSubmission

## Phase 4 - Controller & Routing (MyApp.Web)
Step 5: GradeController.cs
- Index() - dashboard
- Students(string lab) - student table
- StudentDetail(string lab, string student) - per-student detail
- RunStep(string lab, string step, bool rerun) - POST, returns JSON
Step 6: Add Grader nav link in _Layout.cshtml

## Phase 5 - Views (MyApp.Web/Views/Grade/)
Step 7: Index.cshtml - lab dropdown, rerun toggle, step buttons, output panel
Step 8: Students.cshtml - table with compile badge, clickable rows
Step 9: StudentDetail.cshtml - files panel, compile output, grade output

## Relevant Files
- MyApp.Core/src/Models/GradingConfig.cs - new
- MyApp.Core/src/Models/StudentSubmission.cs - new
- MyApp.Core/src/Models/LabInfo.cs - new
- MyApp.Core/src/Services/GradingService.cs - new (full pipeline port)
- MyApp.Core/MyApp.Core.csproj - add SharpCompress
- MyApp.Web/Controllers/GradeController.cs - new
- MyApp.Web/Views/Grade/Index.cshtml - new
- MyApp.Web/Views/Grade/Students.cshtml - new
- MyApp.Web/Views/Grade/StudentDetail.cshtml - new
- MyApp.Web/Program.cs - register GradingService
- MyApp.Web/appsettings.json - add GradeProjectRoot path
- MyApp.Web/Views/Shared/_Layout.cshtml - add nav link

## Key Decisions
- Full C# port, no Python dependency
- os.fork replaced with Task + SemaphoreSlim(32)
- SharpCompress handles tar files
- Configurable grade project root in appsettings.json
- Filesystem is source of truth, no database
