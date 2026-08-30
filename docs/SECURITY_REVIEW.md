# Security Review and Reconstruction Notes

## Portfolio focus

The project demonstrates how to move between C++, assembly, and binary behavior, then use that understanding to identify and remediate insecure implementation choices.

## Findings addressed

| Finding | Risk | Portfolio treatment |
| --- | --- | --- |
| Plaintext password literal in historical exercises | Credential disclosure and trivial authentication bypass | Removed from public candidate; test secret is supplied through `CS410_TEST_PASSWORD` |
| Password comparison against a source constant | No secret rotation or secure storage | Candidate documents the limitation and isolates the test-only environment variable |
| Course scaffold mixed with student work | Misleading authorship signal | Source is grouped by reverse-engineering exercise and claims are limited to demonstrated changes |

The original coursework remains private evidence. The public candidate intentionally does not include Word submissions or compiled artifacts.
