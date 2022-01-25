
#!/usr/bin/env bash

HOME_DIR=$(eval echo ~$username)
OPTIND=1

show_help(){
  echo "-c -> provide commit message and branch is prepended"
}
git_msg() {
  CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
  echo git commit -m "${CURRENT_BRANCH} ${1}"
}



while getopts "bc:" opt; do
  case "$opt" in
    h|\?)
      show_help
      exit 0
      ;;
    c) git_msg "${OPTARG}"
      ;;
    b) rebuild_sh
      ;;
  esac
done
shift $((OPTIND-1))


