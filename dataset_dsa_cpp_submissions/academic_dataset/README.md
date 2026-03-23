# Academic Dataset (Data-Only)

This folder provides a realistic semester dataset for a grading platform.

## Files

- `semesters.json`: term-level metadata.
- `courses.json`: course and section info.
- `students.json`: student records.
- `enrollments.json`: which students are in which section.
- `assignments.json`: assignment definitions and due dates.
- `rubrics.json`: grading criteria by assignment.
- `submissions.json`: submission metadata and file locations.
- `grades.json`: grading outcomes and feedback.
- `users.json`: instructors and teaching assistants.
- `class_sessions.json`: meeting schedule and topics.
- `assignment_extensions.json`: approved student extensions.

## Notes

- This dataset is designed to represent app data shape, not executable code.
- `submission_path` values point to existing sample folders (for assignment `A1`) and placeholder paths for later assignments.
- IDs are normalized so relationships are easy to join (`course_id`, `section_id`, `student_id`, `assignment_id`, `submission_id`).
