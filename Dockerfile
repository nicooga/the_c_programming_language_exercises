FROM gcc:9.4.0-buster
ENV PROJECT_ROOT="/project_root/"
ENV PATH="$PROJECT_ROOT/script:$PATH"
WORKDIR $PROJECT_ROOT
ADD . $PROJECT_ROOT
CMD run_tests