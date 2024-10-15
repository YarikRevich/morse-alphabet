.PHONY: help, prepare, build, install

.ONESHELL:
SHELL := /bin/bash
.DEFAULT_GOAL := help

.PHONY: help
.DEFAULT_GOAL := help
help:
	@grep -h -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: prepare
prepare: ## Install prerequisites
ifeq (,$(wildcard $(shell pwd)/build))
	@mkdir $(shell pwd)/build
endif

.PHONY: build
build: prepare ## Build the project
	@cd $(shell pwd)/build && cmake .. && make

.PHONY: install
install: ## Install built executables to the system directory
	@cd $(shell pwd)/build && make install