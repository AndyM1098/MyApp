#!/usr/bin/env bash
set -euo pipefail

# Use polling watchers to avoid Linux inotify instance limits.
export DOTNET_USE_POLLING_FILE_WATCHER=1

cd "$(dirname "$0")/MyApp.Web"
dotnet watch run
